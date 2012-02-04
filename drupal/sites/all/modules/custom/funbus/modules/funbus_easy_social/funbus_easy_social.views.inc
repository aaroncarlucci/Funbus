<?php

/**
 * @file funbus.views.inc
 */

/**
 * Implementation of hook_views_data();
 */
function funbus_easy_social_views_data() {
  $data = array();
  $data['file_managed']['funbus_video_easy_social'] = array(
    'title' => t('Easy Social: Funbus Video'),
    'help' => t('Display links to social networking websites for Funbus videos.'),
    'field' => array(
      'handler' => 'funbus_easy_social_handler_field_video',
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function funbus_easy_social_views_handlers() {
  $handlers = array();
  $handlers['info']['path'] = drupal_get_path('module', 'funbus_easy_social');
  $handlers['handlers']['funbus_easy_social_handler_field_video'] = array(
    'parent' => 'views_handler_field',
  );
  return $handlers;
}
