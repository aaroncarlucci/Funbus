<?php

class funbus_service_links_handler_field_service_links_youtube extends views_handler_field {
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
    dsm($uri);
    dsm($values);
  }

}