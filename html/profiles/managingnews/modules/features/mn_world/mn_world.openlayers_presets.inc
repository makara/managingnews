<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function mn_world_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn';
  $openlayers_presets->title = 'MN map';
  $openlayers_presets->description = 'A simple basemap of the world.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '200px',
    'image_path' => 'http://js.mapbox.com/theme/dark/',
    'css_path' => '',
    'proxy_host' => '',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508, -20037508, 20037508, 20037508',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoom' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'mn_news_openlayers_2',
        'point_zoom_level' => '5',
      ),
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
    ),
    'default_layer' => 'world_glass_small',
    'layers' => array(
      'world_glass_small' => 'world_glass_small',
      'mn_news_openlayers_2' => 'mn_news_openlayers_2',
    ),
    'layer_styles' => array(
      'mn_news_openlayers_2' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_news_openlayers_2' => 'mn_news_openlayers_2',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => NULL,
  );

  $export['mn'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_channels';
  $openlayers_presets->title = 'MN channels';
  $openlayers_presets->description = 'A simple basemap of the world';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '200px',
    'image_path' => 'http://js.mapbox.com/theme/dark/',
    'css_path' => '',
    'proxy_host' => '',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508, -20037508, 20037508, 20037508',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoom' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'mn_channels_news_openlayers_2',
        'point_zoom_level' => '5',
      ),
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
    ),
    'default_layer' => 'world_glass_small',
    'layers' => array(
      'world_glass_small' => 'world_glass_small',
      'mn_channels_news_openlayers_2' => 'mn_channels_news_openlayers_2',
    ),
    'layer_styles' => array(
      'mn_channels_news_openlayers_2' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_channels_news_openlayers_2' => 'mn_channels_news_openlayers_2',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => NULL,
  );

  $export['mn_channels'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_fullscreen';
  $openlayers_presets->title = 'MN fullscreen';
  $openlayers_presets->description = 'A simple fullscreen map of the world.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => 'auto',
    'image_path' => 'http://js.mapbox.com/theme/dark/',
    'css_path' => '',
    'proxy_host' => '',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508, -20037508, 20037508, 20037508',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
      ),
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
    ),
    'default_layer' => 'world_glass',
    'layers' => array(
      'world_glass' => 'world_glass',
      'osm_mapnik' => 'osm_mapnik',
      'world_dark' => 'world_dark',
      'world_light' => 'world_light',
      'mn_news_openlayers_1' => 'mn_news_openlayers_1',
    ),
    'layer_styles' => array(
      'mn_news_openlayers_1' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_news_openlayers_1' => 'mn_news_openlayers_1',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => NULL,
  );

  $export['mn_fullscreen'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_fullscreen_channels';
  $openlayers_presets->title = 'MN fullscreen channels';
  $openlayers_presets->description = 'A simple fullscreen map of the world.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => 'auto',
    'image_path' => 'http://js.mapbox.com/theme/dark/',
    'css_path' => '',
    'proxy_host' => '',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508, -20037508, 20037508, 20037508',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
      ),
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
    ),
    'default_layer' => 'world_glass',
    'layers' => array(
      'world_glass' => 'world_glass',
      'osm_mapnik' => 'osm_mapnik',
      'world_dark' => 'world_dark',
      'world_light' => 'world_light',
      'mn_channels_news_openlayers_1' => 'mn_channels_news_openlayers_1',
    ),
    'layer_styles' => array(
      'mn_channels_news_openlayers_1' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_channels_news_openlayers_1' => 'mn_channels_news_openlayers_1',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => NULL,
  );

  $export['mn_fullscreen_channels'] = $openlayers_presets;
  return $export;
}
