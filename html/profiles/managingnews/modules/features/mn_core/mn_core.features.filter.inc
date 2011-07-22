<?php

/**
 * Implementation of hook_filter_default_formats().
 */
function mn_core_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML
  $formats['Full HTML'] = array(
    'name' => 'Full HTML',
    'roles' => array(
      '0' => 'admin',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '0',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '1',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '10',
      ),
    ),
  );

  return $formats;
}
