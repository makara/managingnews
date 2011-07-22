<?php

abstract class mn_boxes_default extends boxes_box {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'display_type' => 'listing',
      'number_of_items' => 5,
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    if (filter_access($this->options['format'])) {
      $form['display_type'] = array(
        '#type' => 'radios',
        '#title' => t('Type'),
        '#default_value' => $this->options['type'],
        '#options' => array('listing' => t('Listing'), 'map' => t('Map'), 'graph' => t('Graph')),
      );
      $form['number_of_items'] = array(
        '#type' => 'textfield',
        '#title' => t('Number of items'),
        '#default_value' => $this->options['number_of_items'],
      );
      return $form;
    }
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    $block['title'] = $title;
    $block['subject'] = $title;
    $block['delta'] = $this->delta;
    return $block;
  }
}