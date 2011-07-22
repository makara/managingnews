<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function mn_core_taxonomy_default_vocabularies() {
  return array(
    'tags' => array(
      'name' => 'Tags',
      'description' => '',
      'help' => 'Articles with these tags will appear in this channel.',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '1',
      'tags' => '1',
      'module' => 'features_tags',
      'weight' => '0',
      'nodes' => array(
        'channel' => 'channel',
        'feed' => 'feed',
      ),
    ),
  );
}
