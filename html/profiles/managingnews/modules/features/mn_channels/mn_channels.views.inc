<?php
// $Id$
/**
 * @file
 * Views hooks.
 */

/**
 * Implementation of hook_views_data_alter().
 */
function mn_channels_views_data_alter(&$data) {
  $data['data_taxonomy']['item_count_unmarked'] = array(
    'title' => t('Item count, unmarked'),
    'help' => t('A count of the number of data items related to this tid or nid that are unmarked.'),
    'field' => array(
      'handler' => 'mn_channels_views_handler_field_item_count',
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function mn_channels_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'mn_channels') .'/views',
    ),
    'handlers' => array(
      'mn_channels_views_handler_field_item_count' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}