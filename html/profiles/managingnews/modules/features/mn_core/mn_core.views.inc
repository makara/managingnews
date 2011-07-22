<?php

/**
 * Implementation of hook_views_handlers()
 */
function mn_core_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'mn_core') . '/views',
    ),
    'handlers' => array(
      'mn_core_handler_field' => array(
        'parent' => 'views_handler_field',
      ),
      'mn_core_handler_field_geodata' => array(
        'parent' => 'views_handler_field',
      ),
      'mn_core_handler_relationship_term_data' => array(
        'parent' => 'views_handler_relationship',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function mn_core_views_data_alter(&$data) {
  $tables = data_get_all_tables();
  foreach ($tables as $table) {
    $meta = $table->get('meta');
    if (!empty($meta['data_taxonomy'])) {
      $iterate = $meta['data_taxonomy']['vocabularies'];
      foreach ($iterate as $vid) {
        $vocab = data_taxonomy_get_vocabulary($vid);
        if (_geotaxonomy_vocabulary_enabled($vocab->vid)) {
          // use module name as identifier if features is behind this.
          $usevid = strpos($vocab->module, 'features_') === 0 ? $vocab->module : $vocab->vid;
          $data[$table->get('name')]['term_geo_Lat_'.$usevid] = array(
            'field' => array(
              'title' => t('Geo term lat for %vid', array('%vid' => $usevid)),
              'help' => t('Retrieve geo data if it exists.'),
              'handler' => 'mn_core_handler_field_geodata',
              'real field' => 'lat',
            ),
          );
          $data[$table->get('name')]['term_geo_Lon_'.$usevid] = array(
            'field' => array(
              'title' => t('Geo term lon for %vid', array('%vid' => $usevid)),
              'help' => t('Retrieve geo data if it exists.'),
              'handler' => 'mn_core_handler_field_geodata',
              'real field' => 'lon',
            ),
          );
          $data[$table->get('name')]['term_geo_Feat_'.$usevid] = array(
            'field' => array(
              'title' => t('Geo term feature name for %vid', array('%vid' => $usevid)),
              'help' => t('Retrieve geo data if it exists.'),
              'handler' => 'mn_core_handler_field_geodata',
              'real field' => 'feature',
            ),
          );
        }
      }
    }
  }
}
