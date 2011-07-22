<?php

//require_once drupal_get_path('module', 'mn_test');
require_once drupal_get_path('module', 'simpletest') . '/drupal_web_test_case.php';

/**
 * Test case for typical Drupal tests.
 */
class MnWebTestCase extends DrupalWebTestCase {

  // And we may want to try more install profiles
  var $install_profile = 'managingnews';

  /**
   * Installs Managing News instead of Drupal
   *
   * Generates a random database prefix, runs the install scripts on the
   * prefixed database and enable the specified modules. After installation
   * many caches are flushed and the internal browser is setup so that the
   * page requests will run on the new prefix. A temporary files directory
   * is created with the same name as the database prefix.
   *
   * @param ...
   *   List of modules to enable for the duration of the test.
   */
  protected function setUp() {
    global $db_prefix, $user, $profile;

    // Store necessary current values before switching to prefixed database.
    $this->originalPrefix = $db_prefix;
    $clean_url_original = variable_get('clean_url', 0);

    // Generate temporary prefixed database to ensure that tests have a clean starting point.
    // $db_prefix = Database::getConnection()->prefixTables('{simpletest' . mt_rand(1000, 1000000) . '}');
    $db_prefix = 'simpletest' . mt_rand(1000, 1000000);
    $profile = $this->install_profile;

    // include_once DRUPAL_ROOT . '/includes/install.inc';
    include_once './includes/install.inc';
    drupal_install_system();

    // Add the specified modules to the list of modules in the default profile.
    $args = func_get_args();
    
    // Install modules
    $modules = array_unique(array_merge(drupal_verify_profile($this->install_profile, 'en'), $args));
    drupal_install_modules($modules);

    // Because the schema is static cached, we need to flush
    // it between each run. If we don't, then it will contain
    // stale data for the previous run's database prefix and all
    // calls to it will fail.
    drupal_get_schema(NULL, TRUE);

    if ($this->install_profile == 'managingnews') {
      // Install more modules
      $modules = managingnews_profile_modules();
      drupal_install_modules($modules);
      
      // Install even more modules
      $modules = _managingnews_core_modules();
      drupal_install_modules($modules);

      // Clear views cache before rebuilding menu tree. Requires patch
      // [patch_here] to Views, as new modules have been included and
      // default views need to be re-detected.
      module_exists('views') ? views_get_all_views(TRUE) : TRUE;
      menu_rebuild();
    }

    _drupal_flush_css_js();
    $this->refreshVariables();
    $this->checkPermissions(array(), TRUE);
    user_access(NULL, NULL, TRUE); // Drupal 6.

    // Log in with a clean $user.
    $this->originalUser = $user;
    // drupal_save_session(FALSE);
    // $user = user_load(1);
    session_save_session(FALSE);
    $user = user_load(array('uid' => 1));

    // Restore necessary variables.
    variable_set('install_profile', $this->install_profile);
    variable_set('clean_url', $clean_url_original);
    variable_set('site_mail', 'simpletest@example.com');

    // Other variables worth setting.
    variable_set('site_footer', 'Powered by <a href="http://www.managingnews.com">Managing News</a>.');
    variable_set('site_frontpage', 'dashboard');
    variable_set('comment_channel', 0);
    variable_set('comment_feed', 0);
    variable_set('comment_book', 0);

    _managingnews_system_theme_data();
    db_query("UPDATE {system} SET status = 0 WHERE type = 'theme'");
    db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' AND name = 'jake'");
    db_query("UPDATE {blocks} SET region = '' WHERE theme = 'jake'");
    variable_set('theme_default', 'jake');

    // Use temporary files directory with the same prefix as database.
    $this->originalFileDirectory = file_directory_path();
    variable_set('file_directory_path', file_directory_path() . '/' . $db_prefix);
    $directory = file_directory_path();
    // Create the files directory.
    file_check_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

    set_time_limit($this->timeLimit);
  }

  /**
   * Rewrite assertText function so it prints page when fails
   */
  function assertText($text, $message = '', $group = 'Other') {
    $result = $this->assertTextHelper($text, $message, $group, FALSE);
    if (!$result) {
      $this->printPage();
    }
    return $result;
  }

  /**
   * Rewrite assertUniqueText function so it prints page when fails
   */
  protected function assertUniqueText($text, $message = '', $group = 'Other') {
    $result = $this->assertUniqueTextHelper($text, $message, $group, TRUE);
    if (!$result) {
      $this->printPage();
    }
    return $result;
  }

  /**
   * Print out a variable for debugging
   */
  function printDebug($data, $title = '') {
    $string = is_array($data) || is_object($data) ? print_r($data, TRUE) : $data;
    $output = $title ? $title . ':' . $string : $string;
    //$this->assertTrue(TRUE, $output);
    $this->assertTrue(TRUE, $output, 'Debug');
  }
  /**
   * Debug dump object with some formatting
   */
  function printObject($object, $title = 'Object') {
    $output = $this->formatTable($object);
    $this->printDebug($output, $title);
  }

  /**
   * Print out current HTML page
   */
  function printPage() {
    $this->printDebug($this->drupalGetContent());
  }
  /**
   * Format object as table, recursive
   */
  function formatTable($object) {
    foreach ($object as $key => $value) {
      $rows[] = array(
        $key,
        is_array($value) || is_object($value) ? $this->formatTable($value) : $value,
      );
    }
    if (!empty($rows)) {
      return theme('table', array(), $rows);
    }
    else {
      return 'No properties';
    }
  }

	function loginAdmin() {
    $this->drupalLogin(
      $this->drupalCreateUser(array(
        'administer feeds', 'administer nodes', 'administer content types', 'administer mn', 'mark items'
      ))
    );
	}

  /**
   * Override of refreshVariables().
   */
  protected function refreshVariables() {
    parent::refreshVariables();
    // If strongarm is enabled, we need to reload its variable bootstrap
    // for this page load.
    // @TODO: Do we need to do this for Spaces too?
    if (module_exists('strongarm')) {
      strongarm_set_conf(TRUE);
      $_GET['q'] = strongarm_language_strip($_REQUEST['q']);
      drupal_init_path();
    }
  }
}
