<?php

/**
 * Implementation of hook_views_default_views().
 */
function mn_widgets_views_default_views() {
  $views = array();

  // Exported view: mn_widgets_news
  $view = new view;
  $view->name = 'mn_widgets_news';
  $view->description = '';
  $view->tag = 'mn';
  $view->view_php = '';
  $view->base_table = 'feeds_data_syndication';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'feed_nid' => array(
      'label' => 'feeds_data_syndication.feed_nid -> node.nid',
      'required' => 1,
      'id' => 'feed_nid',
      'table' => 'feeds_data_syndication',
      'field' => 'feed_nid',
      'relationship' => 'none',
    ),
    'data_taxonomy_id' => array(
      'label' => 'Relate a data record to a term tid.',
      'required' => 0,
      'id' => 'data_taxonomy_id',
      'table' => 'feeds_data_syndication',
      'field' => 'data_taxonomy_id',
      'relationship' => 'none',
    ),
    'tid' => array(
      'label' => 'Relate data_taxonomy to a term data.',
      'required' => 0,
      'limit' => 1,
      'vids' => array(
        '2' => 2,
        '1' => 0,
      ),
      'id' => 'tid',
      'table' => 'data_taxonomy',
      'field' => 'tid',
      'relationship' => 'data_taxonomy_id',
    ),
    'vapi_feeds_data_syndication_id' => array(
      'label' => 'Votes',
      'required' => 0,
      'votingapi' => array(
        'value_type' => 'mark',
        'tag' => 'trash',
      ),
      'current_user' => 0,
      'id' => 'vapi_feeds_data_syndication_id',
      'table' => 'feeds_data_syndication',
      'field' => 'vapi_feeds_data_syndication_id',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'url' => array(
      'label' => 'Url',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'display_as_link' => 0,
      'exclude' => 1,
      'id' => 'url',
      'table' => 'feeds_data_syndication',
      'field' => 'url',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'custom',
      'custom_date_format' => 'F j, Y',
      'exclude' => 1,
      'id' => 'timestamp',
      'table' => 'feeds_data_syndication',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '[url]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'hilight_search' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'feeds_data_syndication',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'timestamp_1' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'custom',
      'custom_date_format' => 'g:ia',
      'exclude' => 0,
      'id' => 'timestamp_1',
      'table' => 'feeds_data_syndication',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'title_1' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 1,
        'text' => 'from [title_1]',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'feed_nid',
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'timestamp',
      'table' => 'feeds_data_syndication',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'ignore',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'feed_nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
      ),
      'override' => array(
        'button' => 'Override',
      ),
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'book' => 0,
        'channel' => 0,
        'feed' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
    'name' => array(
      'default_action' => 'ignore',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1 tagged %2',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'glossary' => 0,
      'limit' => '0',
      'case' => 'none',
      'path_case' => 'none',
      'transform_dash' => 0,
      'add_table' => 0,
      'require_value' => 0,
      'id' => 'name',
      'table' => 'term_data',
      'field' => 'name',
      'relationship' => 'tid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
      ),
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'book' => 0,
        'channel' => 0,
        'feed' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'timestamp' => array(
      'operator' => 'between',
      'value' => array(
        'type' => 'offset',
        'value' => '',
        'min' => '-3 months',
        'max' => 'now',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'timestamp',
      'table' => 'feeds_data_syndication',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'value' => array(
      'operator' => 'empty',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'votingapi_vote',
      'field' => 'value',
      'relationship' => 'vapi_feeds_data_syndication_id',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'access content',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 5);
  $handler->override_option('distinct', 1);
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('style_options', array(
    'grouping' => 'timestamp',
    'type' => 'ul',
  ));
  $handler = $view->new_display('web_widgets', 'Widget: News', 'web_widgets_1');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'grouping' => 'timestamp',
    'type' => 'ul',
  ));
  $handler->override_option('path', 'widget/feeds');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array(
    'default' => 0,
    'page_1' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('web_widgets', 'Widget: Map', 'web_widgets_2');
  $handler->override_option('style_plugin', 'openlayers_map');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'preset' => 'mn',
  ));
  $handler->override_option('path', 'widget/map/feeds');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('web_widgets', 'Widget: Search', 'web_widgets_3');
  $handler->override_option('filters', array(
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'search',
        'label' => '',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'operator' => 'between',
      'value' => array(
        'type' => 'offset',
        'value' => '',
        'min' => '-3 months',
        'max' => 'now',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'timestamp',
      'table' => 'feeds_data_syndication',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'value' => array(
      'operator' => 'empty',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'votingapi_vote',
      'field' => 'value',
      'relationship' => 'vapi_feeds_data_syndication_id',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('path', 'widget/search');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('web_widgets', 'Widget: Search Map', 'web_widgets_4');
  $handler->override_option('filters', array(
    'keys' => array(
      'operator' => 'optional',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'keys_op',
        'identifier' => 'search',
        'label' => '',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'keys',
      'table' => 'search_index',
      'field' => 'keys',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'operator' => 'between',
      'value' => array(
        'type' => 'offset',
        'value' => '',
        'min' => '-3 months',
        'max' => 'now',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'timestamp',
      'table' => 'feeds_data_syndication',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'value' => array(
      'operator' => 'empty',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'votingapi_vote',
      'field' => 'value',
      'relationship' => 'vapi_feeds_data_syndication_id',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('style_plugin', 'openlayers_map');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'preset' => 'mn',
  ));
  $handler->override_option('path', 'widget/map/search');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('web_widgets', 'Widget: News in channel', 'web_widgets_5');
  $handler->override_option('relationships', array(
    'feed_nid' => array(
      'label' => 'feeds_data_syndication.feed_nid -> node.nid',
      'required' => 1,
      'id' => 'feed_nid',
      'table' => 'feeds_data_syndication',
      'field' => 'feed_nid',
      'relationship' => 'none',
    ),
    'tid_2' => array(
      'label' => 'Relate data taxonomy to nodes with term.',
      'required' => 1,
      'id' => 'tid_2',
      'table' => 'data_taxonomy',
      'field' => 'tid_2',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'vapi_feeds_data_syndication_id' => array(
      'label' => 'Votes',
      'required' => 0,
      'votingapi' => array(
        'value_type' => 'mark',
        'tag' => 'trash',
      ),
      'current_user' => 0,
      'id' => 'vapi_feeds_data_syndication_id',
      'table' => 'feeds_data_syndication',
      'field' => 'vapi_feeds_data_syndication_id',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1',
      'breadcrumb' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'tid_2',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'book' => 0,
        'channel' => 0,
        'feed' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'value' => array(
      'operator' => 'empty',
      'value' => array(
        'value' => '',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'value',
      'table' => 'votingapi_vote',
      'field' => 'value',
      'relationship' => 'vapi_feeds_data_syndication_id',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('path', 'widget/channel');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler = $view->new_display('web_widgets', 'Widget: Channel Map', 'web_widgets_6');
  $handler->override_option('style_plugin', 'openlayers_map');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'preset' => 'mn_channels',
  ));
  $handler->override_option('path', 'widget/map/channel');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);

  $views[$view->name] = $view;

  return $views;
}
