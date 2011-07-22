<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_search_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-search';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search*' => 'search*',
        'stored-views*' => 'stored-views*',
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
        'views--exp-mn_news-page_2' => array(
          'module' => 'views',
          'delta' => '-exp-mn_news-page_2',
          'region' => 'page_title',
          'weight' => 0,
        ),
        'stored_views-save' => array(
          'module' => 'stored_views',
          'delta' => 'save',
          'region' => 'page_title',
          'weight' => 1,
        ),
        'views-mn_search_saved-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_search_saved-block_2',
          'region' => 'left',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $translatables['mn-section-search'] = array(

  );

  $export['mn-section-search'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-search-notrash';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'mn_news:page_2' => 'mn_news:page_2',
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
        'mn_search-status' => array(
          'module' => 'mn_search',
          'delta' => 'status',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-mn_news-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_news-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-mn_news-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_news-block_2',
          'region' => 'right',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  $translatables['mn-section-search-notrash'] = array(

  );

  $export['mn-section-search-notrash'] = $context;
  return $export;
}
