<?php
// $Id: dimdim.views.inc,v 1.1 2009/12/11 00:47:11 univate Exp $

/**
 * @file
 * Implementations of Views 2 Hooks for Dimdim
 *
 */

/**
 * Implementation of hook_views_handlers()
 */
function dimdim_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'dimdim') .'/views',
    ),
    'handlers' => array(
      'dimdim_handler_field_recording' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data()
 */
function dimdim_views_data() {
  $data['dimdim'] = array(
    'table' => array(
      'group' => 'Dimdim Conference',
      'title' => 'Dimdim',
      'join' => array(
         'node' => array(
           'left_field' => 'nid',
           'field' => 'nid',
        ),
      ),
    ),
    'start_date' => array(
      'title' => t('Date'),
      'help' => t('The conference date.'),
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => true,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'recording' => array(
      'title' => t('Recording'),
      'help' => t('Link to recording.'),
      'field' => array(
        'handler' => 'dimdim_handler_field_recording',
        'click sortable' => false,
      ),
    ),
  );
  
  return $data;
}
