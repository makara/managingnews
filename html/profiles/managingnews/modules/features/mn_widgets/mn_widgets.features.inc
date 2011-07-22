<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_widgets_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-widgets';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'mn_channels_news:page_1' => 'mn_channels_news:page_1',
        'mn_news:page_1' => 'mn_news:page_1',
        'mn_news:page_2' => 'mn_news:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mn_widgets-embed' => array(
          'module' => 'mn_widgets',
          'delta' => 'embed',
          'region' => 'palette',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $translatables['mn-widgets'] = array(

  );

  $export['mn-widgets'] = $context;
  return $export;
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mn_widgets_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_views_api().
 */
function mn_widgets_views_api() {
  return array(
    'api' => '2',
  );
}
