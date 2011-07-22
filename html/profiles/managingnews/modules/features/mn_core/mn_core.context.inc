<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_core_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-dashboard';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'dashboard' => 'dashboard',
        'dashboard/*' => 'dashboard/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'spaces_dashboard-editor' => array(
          'module' => 'spaces_dashboard',
          'delta' => 'editor',
          'region' => 'palette',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['mn-dashboard'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-display_mode-list';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views_modes' => array(
      'values' => array(
        'views-mode-list' => 'views-mode-list',
      ),
    ),
  );
  $context->reactions = array(
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'views-mode-list',
    ),
  );
  $context->condition_mode = 0;

  $export['mn-display_mode-list'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-display_mode-map';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views_modes' => array(
      'values' => array(
        'views-mode-map' => 'views-mode-map',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'sidebar',
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'views-mode-map',
    ),
  );
  $context->condition_mode = 0;

  $export['mn-display_mode-map'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-display_mode-trash';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views_modes' => array(
      'values' => array(
        'views-mode-trash' => 'views-mode-trash',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-trash' => array(
          'module' => 'boxes',
          'delta' => 'trash',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'views-mode-list views-mode-trash',
    ),
  );
  $context->condition_mode = 0;

  $export['mn-display_mode-trash'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-global-context';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-0' => array(
          'module' => 'user',
          'delta' => 0,
          'region' => 'palette',
          'weight' => 0,
        ),
        'mn_core-user' => array(
          'module' => 'mn_core',
          'delta' => 'user',
          'region' => 'palette',
          'weight' => 1,
        ),
        'mn_core-clock' => array(
          'module' => 'mn_core',
          'delta' => 'clock',
          'region' => 'palette',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['mn-global-context'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-admin';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin' => 'admin',
        'admin/*' => 'admin/*',
        'import' => 'import',
        'import/*' => 'import/*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mn_core-admin' => array(
          'module' => 'mn_core',
          'delta' => 'admin',
          'weight' => 21,
          'region' => 'left',
          'status' => '0',
          'label' => 'MN: Admin menu',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $export['mn-section-admin'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-news';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'feed' => 'feed',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'views' => array(
      'values' => array(
        'mn_news:page_1' => 'mn_news:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mn_core-print' => array(
          'module' => 'mn_core',
          'delta' => 'print',
          'region' => 'palette',
          'weight' => 0,
        ),
        'views_modes-modes' => array(
          'module' => 'views_modes',
          'delta' => 'modes',
          'region' => 'page_tools',
          'weight' => 0,
        ),
        'mn_core-formats' => array(
          'module' => 'mn_core',
          'delta' => 'formats',
          'region' => 'page_tools',
          'weight' => 1,
        ),
        'views-mn_feeds-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_feeds-block_1',
          'region' => 'left',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'feeds',
  );
  $context->condition_mode = 0;

  $export['mn-section-news'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-news-notrash';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'mn_news:page_1' => 'mn_news:page_1',
      ),
    ),
    'views_modes' => array(
      'values' => array(
        'default' => 'default',
        'views-mode-list' => 'views-mode-list',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-mn_news-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_news-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-mn_news-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_news-block_2',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  $export['mn-section-news-notrash'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'spaces_dashboard-custom-1';
  $context->description = 'Dashboard';
  $context->tag = 'Dashboard';
  $context->conditions = array();
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-mn_welcome' => array(
          'module' => 'boxes',
          'delta' => 'mn_welcome',
          'region' => 'content',
          'weight' => 0,
        ),
        'boxes-mn_latest_news_map' => array(
          'module' => 'boxes',
          'delta' => 'mn_latest_news_map',
          'region' => 'content',
          'weight' => 1,
        ),
        'boxes-mn_latest_news' => array(
          'module' => 'boxes',
          'delta' => 'mn_latest_news',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard');

  $export['spaces_dashboard-custom-1'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'theme-layout-wide';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/add/*' => 'node/add/*',
        'node/*/edit' => 'node/*/edit',
        'admin' => 'admin',
        'admin/*' => 'admin/*',
        'user/*/edit' => 'user/*/edit',
        'user/*/edit/*' => 'user/*/edit/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'sidebar',
    ),
  );
  $context->condition_mode = 0;

  $export['theme-layout-wide'] = $context;
  return $export;
}
