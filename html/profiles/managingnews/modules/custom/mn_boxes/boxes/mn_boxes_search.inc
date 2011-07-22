<?php

class mn_boxes_search extends mn_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    $options['search_terms'] = '';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    $form['search_terms'] = array(
      '#type' => 'textfield',
      '#title' => t('Search terms'),
      '#default_value' => $this->options['search_terms']
    );
    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $view = views_get_view('mn_news');

    switch ($this->options['display_type']) {
      case 'listing':
        $view->set_display('block_3');
        $view->display_handler->set_option('items_per_page', $this->options['number_of_items']);
        break;
      case 'map':
        $view->set_display('block_2');
        break;
      case 'graph':
        $view->set_display('block_1');
        break;
    }
    if (!empty($this->options['search_terms'])) {
      $view->set_exposed_input(array('search' => $this->options['search_terms']));
    }
    $output = $view->execute_display();
    $block = parent::render();
    $block['content'] = $output['content'];
    return $block;
  }

}