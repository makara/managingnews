<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_channels_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-channels';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'channel' => 'channel',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'views' => array(
      'values' => array(
        'mn_channels' => 'mn_channels',
        'mn_channels_news' => 'mn_channels_news',
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
        'views-mn_channels-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_channels-block_1',
          'region' => 'left',
          'weight' => 0,
        ),
        'views-mn_channels-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_channels-block_2',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'channels',
  );
  $context->condition_mode = 0;

  $export['mn-section-channels'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-channels-notrash';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'mn_channels_news' => 'mn_channels_news',
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
        'views-mn_channels_news-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_channels_news-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-mn_channels_news-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_channels_news-block_2',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  $export['mn-section-channels-notrash'] = $context;
  return $export;
}
