<?php

class mn_boxes_feed extends mn_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    $options['feed'] = 0;
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    $result = db_query(db_rewrite_sql("SELECT nid, title FROM {node} WHERE type = 'feed' ORDER BY title"));
    $feeds = array(0 => '<'. t('All feeds') .'>');
    while ($row = db_fetch_array($result)) {
      $feeds[$row['nid']] = $row['title'];
    }
    $form['feed'] = array(
      '#type' => 'select',
      '#title' => t('Feed'),
      '#options' => $feeds,
      '#default_value' => $this->options['feed']
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

    if ($this->options['feed']) {
      $view->set_arguments(array($this->options['feed']));
    }
    $output = $view->execute_display();
    $block = parent::render();
    $block['content'] = $output['content'];
    return $block;
  }

}