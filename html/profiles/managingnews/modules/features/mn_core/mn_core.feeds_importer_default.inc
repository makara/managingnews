<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function mn_core_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'opml';
  $feeds_importer->config = array(
    'name' => 'Import OPML',
    'description' => 'Import OPML files and create new feed subscriptions from it.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsOPMLParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFeedNodeProcessor',
      'config' => array(
        'content_type' => 'feed',
        'update_existing' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xmlurl',
            'target' => 'source',
            'unique' => 1,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['opml'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'syndication';
  $feeds_importer->config = array(
    'name' => 'Syndication',
    'description' => 'Aggregates syndicated content.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'ExtractorSyndicationParser',
      'config' => array(
        'extractors' => 'extractor_simple',
        'language' => 'en-US',
        'placemaker_key' => '',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'timestamp',
            'target' => 'timestamp',
            'unique' => 0,
          ),
          5 => array(
            'source' => 'extracted_terms',
            'target' => 'data_taxonomy:features_tags',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'tags',
            'target' => 'data_taxonomy:features_tags',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'geolocations',
            'target' => 'data_taxonomy:features_tags',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'parent:taxonomy:features_tags',
            'target' => 'data_taxonomy:features_tags',
            'unique' => FALSE,
          ),
        ),
        'expire' => '7257600',
        'delete_with_source' => 1,
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_on_create' => 1,
    'import_period' => '1800',
  );

  $export['syndication'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'terms';
  $feeds_importer->config = array(
    'name' => 'Terms',
    'description' => 'Imports terms that are used for automatically tagging incoming items. Can be plain terms with only a name or geo terms.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'ExtractorTermProcessor',
      'config' => array(
        'vocabulary' => 'features_tags',
        'update_existing' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'lat',
            'target' => 'lat',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'lon',
            'target' => 'lon',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'top',
            'target' => 'bound_top',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'right',
            'target' => 'bound_right',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'bottom',
            'target' => 'bound_bottom',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'left',
            'target' => 'bound_left',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'parent',
            'target' => 'parent_name',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'id',
            'target' => 'external_id',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'parent_id',
            'target' => 'parent_external_id',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_on_create' => 1,
    'import_period' => '-1',
  );

  $export['terms'] = $feeds_importer;
  return $export;
}
