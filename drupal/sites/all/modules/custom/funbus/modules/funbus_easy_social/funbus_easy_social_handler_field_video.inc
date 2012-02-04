<?php

class funbus_easy_social_handler_field_video extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['uri'] = 'uri';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Remove the alteration stuff
    unset($form['alter']);
  }

  function render($values) {
    $uri = $values->{$this->aliases['uri']};

    if (isset($values->node_title)) {
      $enabled_widgets = variable_get_value("easy_social_video_widgets");
      $widgets = _easy_social_render_widgets(file_create_url($uri), $values->node_title);
      return theme('easy_social_links', array('widgets' => $widgets, 'widget_type' => $type));
    }

  }

}