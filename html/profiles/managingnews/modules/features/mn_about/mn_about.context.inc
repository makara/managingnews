<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_about_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-about';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'book' => 'book',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'book-0' => array(
          'module' => 'book',
          'delta' => 0,
          'region' => 'left',
          'weight' => 0,
        ),
      ),
      'layout' => 'sidebar',
    ),
  );
  $context->condition_mode = 0;

  $translatables['mn-section-about'] = array(

  );

  $export['mn-section-about'] = $context;
  return $export;
}
