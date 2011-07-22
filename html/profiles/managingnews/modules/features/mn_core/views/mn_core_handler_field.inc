<?php
/**
 * @file
 * Class definition of mn_core_handler_field.
 */

/**
 * Highlights search keys in text.
 */
class mn_core_handler_field extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    $options['hilight_search'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['hilight_search'] = array(
      '#title' => t('Hilight search results'),
      '#type' => 'checkbox',
      '#description' => t('If enabled, any occurrences of a Views search will be hilighted in this text.'),
      '#default_value' => $this->options['hilight_search'],
    );
  }

  function render($values) {
    $value = $this->autoformat($values);

    // If someone has performed a search, try to find & hilight the relevant text.
    if (!empty($this->options['hilight_search']) && !empty($this->view->exposed_input['search'])) {
      $search = check_plain($this->view->exposed_input['search']);
      $patterns = array();
      $replacements = array();
      foreach (explode(' ', $search) as $word) {
        $patterns[] = '/([^<]*)('. preg_quote($word) .')([^>*])/i';
        $replacements[] = '${1}<span class="search-found">${2}</span>${3}';
      }
      $value = preg_replace($patterns, $replacements, $value);
    }

    return filter_xss_admin($value);
  }

  /**
   * Autoformat dispatcher. Attempts to autoformat content on the basis of its feed source.
   */
  protected function autoformat($values) {
    $value = $values->{$this->field_alias};
    if (isset($this->view->field['config']) && $this->view->field['config']->table == 'feeds_source') {
      $domain = mn_core_get_domain($this->view->field['config']->render($values));
      $method = "autoformat_" . str_replace('-', '_', $domain);
      if (method_exists($this, $method)) {
        $value = $this->$method($value, $values);
      }
    }
    return $value;
  }

  /**
   * NEWS.GOOGLE.COM
   */
  protected function autoformat_news_google_com($value, $values) {
    if ($this->field === 'description') {
      $value = filter_xss($value, array('a', 'div', 'font', 'br'));
      $segments = array_values(array_filter(preg_split('/(<[^>]+?>)/', $value, -1)));

      // Attempt to identify body by length of the string segment.
      foreach ($segments as $index => $segment) {
        if (strlen($segment) > 100) {
          $output = "<p>{$segment}</p>";
          if (isset($segments[$index+1], $segments[$index+2])) {
            $output .= '<cite><em>';
            $output .= $segments[$index+1];
            $output .= '</em> - ';
            $output .= $segments[$index+2];
            $output .= '</cite>';
          }
          return $output;
        }
      }
    }
    return $value;
  }

  /**
   * SEARCH.TWITTER.COM
   */
  protected function autoformat_search_twitter_com($value, $values) {
    // @TODO
    // - Determine why author mapping is failing in simplepie.
    // - Parse author name from twitter search RSS format.
    // - Link author name back to twitter.com/[author]
    return $value;
  }

  /**
   * TWITTER.COM
   */
  protected function autoformat_twitter_com($value, $values) {
    // Format twitter #, @ tags
    $value = strip_tags($value);
    $value = $this->twitter_link_filter($value);
    $value = $this->twitter_link_filter($value, '#', 'http://search.twitter.com/search?q=%23');

    // Link urls
    $value = module_invoke('filter', 'filter', 'process', 2, -1, $value);

    $destination = 'http://www.twitter.com/';
    $matches = array('/([a-zA-Z0-9_]{0,15})(: )/');
    $replacements = array('<a href="' . $destination . '${1}">${1}</a>${2}');
    return preg_replace($matches, $replacements, $value, 1);

    return $value;
  }

  /**
  * Taken from the twitter module by walkah.
  * This helper function converts Twitter-style @usernames and #hashtags into
  * actual links.
  */
  protected function twitter_link_filter($text, $prefix = '@', $destination = 'http://twitter.com/') {
    $matches = array(
      '/\>' . $prefix . '([a-zA-Z0-9_]{0,15})/i',
      '/^' . $prefix . '([a-zA-Z0-9_]{0,15})/i',
      '/(\s+)' . $prefix . '([a-zA-Z0-9_]{0,15})/i',
    );
    $replacements = array(
      '><a href="' . $destination . '${1}">' . $prefix . '${1}</a>',
      '<a href="' . $destination . '${1}">' . $prefix . '${1}</a>',
      '${1}<a href="' . $destination . '${2}">' . $prefix . '${2}</a>',
    );
    return preg_replace($matches, $replacements, $text);
  }
}
