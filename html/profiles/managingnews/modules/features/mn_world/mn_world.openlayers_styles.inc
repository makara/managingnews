<?php

/**
 * Implementation of hook_openlayers_styles().
 */
function mn_world_openlayers_styles() {
  $export = array();
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'mn_blue';
  $openlayers_styles->title = 'Blue';
  $openlayers_styles->description = 'Blue point.';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#66eeff',
    'strokeColor' => '#33ccff',
    'strokeWidth' => 10,
    'strokeOpacity' => 0.35,
    'fillOpacity' => 0.75,
  );

  $export['mn_blue'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'mn_green';
  $openlayers_styles->title = 'Green';
  $openlayers_styles->description = 'Green point.';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#33ff33',
    'strokeColor' => '#99ff33',
    'strokeWidth' => 10,
    'strokeOpacity' => 0.35,
    'fillOpacity' => 0.75,
  );

  $export['mn_green'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'mn_red';
  $openlayers_styles->title = 'Red';
  $openlayers_styles->description = 'Red point.';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#ff4400',
    'strokeColor' => '#ff8844',
    'strokeWidth' => 10,
    'strokeOpacity' => 0.35,
    'fillOpacity' => 0.75,
  );

  $export['mn_red'] = $openlayers_styles;
  return $export;
}
