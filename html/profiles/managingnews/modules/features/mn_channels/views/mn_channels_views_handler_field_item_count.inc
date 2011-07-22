<?php
// $Id$
/**
 * @file
 * Class defition for data_node_views_handler_field_item_count.
 */

class mn_channels_views_handler_field_item_count extends views_handler_field {
  function query() { return; }

  function pre_render($result) {
    $this->items = array();
    foreach ($result as $row) {
      if (!empty($row->{$this->view->base_field})) {
        $tid = $row->{$this->view->base_field};
        if ($this->view->base_table == 'node') {
          $this->items[$tid] = db_result(db_query("SELECT COUNT(DISTINCT dt.id) AS count FROM {node} n LEFT JOIN {term_node} tn ON tn.nid = n.nid LEFT JOIN {data_taxonomy} dt ON dt.tid = tn.tid INNER JOIN {feeds_data_syndication} fds ON fds.id = dt.id LEFT JOIN {votingapi_vote} vapi ON fds.id = vapi.content_id  AND vapi.content_type = 'feeds_data_syndication' WHERE n.nid = %d AND vapi.value IS NULL", $tid));
        } else {
          $this->items[$tid] = db_result(db_query("SELECT COUNT(dt.id) AS count FROM {data_taxonomy} dt INNER JOIN {feeds_data_syndication} fds ON fds.id = dt.id LEFT JOIN {votingapi_vote} vapi ON fds.id = vapi.content_id  AND vapi.content_type = 'feeds_data_syndication' WHERE tid = %d AND vapi.value IS NULL", $tid));
        }
      }
    }
  }

  function render($values) {
    if (!empty($values->{$this->view->base_field})) {
      $tid = $values->{$this->view->base_field};
      if (isset($this->items[$tid])) {
        return check_plain($this->items[$tid]);
      }
    }
    return 0;
  }
}
