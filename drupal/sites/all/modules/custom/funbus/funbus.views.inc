<?php

/**
 * @file funbus.views.inc
 */

/**
 * Implementation of hook_views_data();
 */
function funbus_views_data() {
  $data = array();
  $data['file_managed']['service_links_youtube'] = array(
    'title' => t('Service Links: YouTube'),
    'help' => t('Display links to social networking websites for YouTube videos.'),
    'field' => array(
      'handler' => 'funbus_service_links_handler_field_service_links_youtube',
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function funbus_views_handlers() {
  $handlers = array();
  $handlers['info']['path'] = drupal_get_path('module', 'funbus');
  $handlers['handlers']['funbus_service_links_handler_field_service_links_youtube'] = array(
    'parent' => 'views_handler_field',
  );
  return $handlers;
}

function funbus_views_data_alter(&$views_data) {
  #dsm($views_data);
}