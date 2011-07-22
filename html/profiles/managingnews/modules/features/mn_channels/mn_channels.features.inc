<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mn_channels_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function mn_channels_node_info() {
  $items = array(
    'channel' => array(
      'name' => t('Channel'),
      'module' => 'features',
      'description' => t('A channel is a collection of articles that the world can subscribe to.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function mn_channels_views_api() {
  return array(
    'api' => '2',
  );
}
