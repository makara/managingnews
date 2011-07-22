<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function mn_channels_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: features:channels
  $menu_links['features:channels'] = array(
    'menu_name' => 'features',
    'link_path' => 'channels',
    'router_path' => 'channels',
    'link_title' => 'Channels',
    'options' => array(
      'attributes' => array(
        'title' => 'Channels contain news organized around topics. People can view, print and subscribe to the items in channels.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Channels');


  return $menu_links;
}
