<?php

/**
 * Implementation of hook_openlayers_layers().
 */
function mn_world_openlayers_layers() {
  $export = array();
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_dark';
  $openlayers_layers->title = 'World Borders - Dark';
  $openlayers_layers->description = 'World Borders - Dark';
  $openlayers_layers->data = array(
    'title' => 'World Borders - Dark',
    'layername' => 'world-dark',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'projection' => array(
      0 => '900913',
    ),
    'maxExtent' => array(
      0 => -20037508,
      1 => -20037508,
      2 => 20037508,
      3 => 20037508,
    ),
    'baselayer' => TRUE,
    'serverResolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.96980938,
      6 => 2445.98490469,
      7 => 1222.99245234,
      8 => 611.496226172,
      9 => 305.748113086,
      10 => 152.874056543,
      11 => 76.4370282715,
      12 => 38.2185141357,
      13 => 19.1092570679,
      14 => 9.55462853394,
      15 => 4.77731426697,
      16 => 2.38865713348,
      17 => 1.19432856674,
      18 => 0.597164283371,
    ),
    'resolutions' => array(
      0 => 39135.758475,
      1 => 19567.8792375,
      2 => 9783.93961875,
      3 => 4891.96980938,
      4 => 2445.98490469,
      5 => 1222.99245234,
      6 => 611.496226172,
      7 => 305.748113086,
    ),
    'layer_handler' => 'MapBox',
    'url' => array(
      0 => 'http://a.tile.mapbox.com/',
      1 => 'http://b.tile.mapbox.com/',
      2 => 'http://c.tile.mapbox.com/',
      3 => 'http://d.tile.mapbox.com/',
    ),
    'events' => array(),
    'callback' => 'mn_core_process_layers',
  );

  $export['world_dark'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_glass';
  $openlayers_layers->title = 'World Glass';
  $openlayers_layers->description = 'World Glass';
  $openlayers_layers->data = array(
    'layername' => 'world-glass',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'osm' => 0,
    'baselayer' => 1,
    'type' => 'png',
    'resolutions' => array(
      0 => 39135.758475,
      1 => 19567.8792375,
      2 => 9783.93961875,
      3 => 4891.969809375,
      4 => 2445.9849046875,
      5 => 1222.9924523438,
    ),
    'projection' => array(
      0 => '900913',
    ),
  );

  $export['world_glass'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_glass_small';
  $openlayers_layers->title = 'World Glass';
  $openlayers_layers->description = 'World Glass (for small maps)';
  $openlayers_layers->data = array(
    'layername' => 'world-glass',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'osm' => 0,
    'baselayer' => 1,
    'type' => 'png',
    'resolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.969809375,
      6 => 2445.9849046875,
      7 => 1222.9924523438,
    ),
    'projection' => array(
      0 => '900913',
    ),
  );

  $export['world_glass_small'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_light';
  $openlayers_layers->title = 'World Borders - Light';
  $openlayers_layers->description = 'World Borders - Light';
  $openlayers_layers->data = array(
    'title' => 'World Borders - Light',
    'layername' => 'world-light',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'projection' => array(
      0 => '900913',
    ),
    'maxExtent' => array(
      0 => -20037508,
      1 => -20037508,
      2 => 20037508,
      3 => 20037508,
    ),
    'baselayer' => TRUE,
    'serverResolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.96980938,
      6 => 2445.98490469,
      7 => 1222.99245234,
      8 => 611.496226172,
      9 => 305.748113086,
      10 => 152.874056543,
      11 => 76.4370282715,
      12 => 38.2185141357,
      13 => 19.1092570679,
      14 => 9.55462853394,
      15 => 4.77731426697,
      16 => 2.38865713348,
      17 => 1.19432856674,
      18 => 0.597164283371,
    ),
    'resolutions' => array(
      0 => 39135.758475,
      1 => 19567.8792375,
      2 => 9783.93961875,
      3 => 4891.96980938,
      4 => 2445.98490469,
      5 => 1222.99245234,
      6 => 611.496226172,
      7 => 305.748113086,
    ),
    'layer_handler' => 'MapBox',
    'url' => array(
      0 => 'http://a.tile.mapbox.com/',
      1 => 'http://b.tile.mapbox.com/',
      2 => 'http://c.tile.mapbox.com/',
      3 => 'http://d.tile.mapbox.com/',
    ),
    'events' => array(),
    'callback' => 'mn_core_process_layers',
  );

  $export['world_light'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_light_small';
  $openlayers_layers->title = 'World Borders - Light';
  $openlayers_layers->description = 'World Borders - Light (for small maps)';
  $openlayers_layers->data = array(
    'title' => 'World Borders - Light',
    'layername' => 'world-light',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'projection' => array(
      0 => '900913',
    ),
    'maxExtent' => array(
      0 => -20037508,
      1 => -20037508,
      2 => 20037508,
      3 => 20037508,
    ),
    'baselayer' => TRUE,
    'serverResolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.96980938,
      6 => 2445.98490469,
      7 => 1222.99245234,
      8 => 611.496226172,
      9 => 305.748113086,
      10 => 152.874056543,
      11 => 76.4370282715,
      12 => 38.2185141357,
      13 => 19.1092570679,
      14 => 9.55462853394,
      15 => 4.77731426697,
      16 => 2.38865713348,
      17 => 1.19432856674,
      18 => 0.597164283371,
    ),
    'resolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.96980938,
      6 => 2445.98490469,
      7 => 1222.99245234,
      8 => 611.496226172,
      9 => 305.748113086,
    ),
    'layer_handler' => 'MapBox',
    'url' => array(
      0 => 'http://a.tile.mapbox.com/',
      1 => 'http://b.tile.mapbox.com/',
      2 => 'http://c.tile.mapbox.com/',
      3 => 'http://d.tile.mapbox.com/',
    ),
    'events' => array(),
    'callback' => 'mn_core_process_layers',
  );

  $export['world_light_small'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_print';
  $openlayers_layers->title = 'World Print';
  $openlayers_layers->description = 'A printer-friendly world map';
  $openlayers_layers->data = array(
    'layername' => 'world-print',
    'layer_type' => 'openlayers_layer_type_mapbox',
    'osm' => 0,
    'baselayer' => 1,
    'type' => 'png',
    'resolutions' => array(
      0 => 78271.51695,
      1 => 39135.758475,
      2 => 19567.8792375,
      3 => 9783.93961875,
      4 => 4891.969809375,
      5 => 2445.9849046875,
      6 => 1222.9924523438,
      7 => 611.49622617188,
      8 => 305.74811308594,
    ),
    'projection' => array(
      0 => '900913',
    ),
  );

  $export['world_print'] = $openlayers_layers;
  return $export;
}
