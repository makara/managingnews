<?php

/**
 * Implementation of hook_mark_default_marks().
 */
function mn_core_mark_default_marks() {
  $export = array();
  $mark = new stdClass;
  $mark->disabled = FALSE; /* Edit this to true to make a default mark disabled initially */
  $mark->api_version = 1;
  $mark->name = 'trash';
  $mark->basetable = 'feeds_data_syndication';
  $mark->settings = array(
    'title' => 'trash',
    'mark_text' => 'Remove',
    'mark_confirm_text' => 'Removed',
    'unmark_text' => 'Restore',
    'unmark_confirm_text' => 'Restored',
    'global' => 1,
  );

  $export['trash'] = $mark;
  return $export;
}
