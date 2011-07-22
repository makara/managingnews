<?php

/**
 * Implementation of hook_strongarm().
 */
function mn_about_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_block_mode';
  $strongarm->value = 'book pages';

  $export['book_block_mode'] = $strongarm;
  return $export;
}
