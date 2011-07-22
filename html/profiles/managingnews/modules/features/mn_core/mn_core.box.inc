<?php

/**
 * Implementation of hook_default_box().
 */
function mn_core_default_box() {
  $export = array();
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mn_latest_news';
  $box->plugin_key = 'mn_boxes_feed';
  $box->title = 'Latest News';
  $box->description = 'Latest News';
  $box->options = array(
    'display_type' => 'listing',
    'number_of_items' => '5',
    'feed' => '0',
  );

  $export['mn_latest_news'] = $box;
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mn_latest_news_map';
  $box->plugin_key = 'mn_boxes_feed';
  $box->title = 'News on the Map';
  $box->description = 'News on the Map';
  $box->options = array(
    'display_type' => 'map',
    'number_of_items' => '5',
    'feed' => '0',
  );

  $export['mn_latest_news_map'] = $box;
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mn_welcome';
  $box->plugin_key = 'simple';
  $box->title = 'Welcome';
  $box->description = 'Welcome';
  $box->options = array(
    'body' => 'Customize this text to describe your Managing News site.',
    'format' => '1',
  );

  $export['mn_welcome'] = $box;
  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'trash';
  $box->plugin_key = 'simple';
  $box->title = 'Trash';
  $box->description = 'Trash';
  $box->options = array(
    'body' => 'The trash listing shows removed stories matching the current filters. Only admins can see it. You can click to restore items back to public listings.',
    'format' => '1',
  );

  $export['trash'] = $box;
  return $export;
}
