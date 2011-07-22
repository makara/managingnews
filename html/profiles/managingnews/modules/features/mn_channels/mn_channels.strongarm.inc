<?php

/**
 * Implementation of hook_strongarm().
 */
function mn_channels_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_channel';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_channel'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_channel';
  $strongarm->value = '0';

  $export['upload_channel'] = $strongarm;
  return $export;
}
