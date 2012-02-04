<?php

/**
* Handler for showing Easy Social share buttons in views
 */
class easy_social_handler_field extends views_handler_field {
  function construct() {
    parent::construct();

    // Add the node fields that easy_social will need..
    $this->additional_fields['nid'] = array(
      'field' => 'nid',
    );
    $this->additional_fields['type'] = array(
      'field' => 'type',
    );
    $this->additional_fields['title'] = array(
      'field' => 'title',
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Build fake $node.
    $node = new stdClass();
    $node->nid      = $this->get_value($values, 'nid');
    $node->title      = $this->get_value($values, 'title');
    $node->type     = $this->get_value($values, 'type');

    /**
     * Load the widgets for each node
     *
     * @todo Load widget settings by fields, but with the possibility to inherit the
     * global settings or even the settings by content type.
     */
    $widgets = _easy_social_render_widgets(url('node/' . $node->nid, array('absolute' => TRUE)), $node->title);

    return theme('easy_social_links', array('widgets' => $widgets));
  }
}
