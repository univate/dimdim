<?php
// $Id: dimdim.views_default.inc,v 1.1 2009/12/11 00:47:11 univate Exp $
/**
 * @file
 * Default views for Dimdim module
 */

/**
 * Implementation of hook_views_default_views().
 */
function dimdim_views_default_views() {
  $view = new view;
  $view->name = 'dimdim';
  $view->description = 'View list of dimdim conferences';
  $view->tag = 'Dimdim';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'start_date' => array(
      'label' => 'Date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
      'relationship' => 'none',
    ),
    'recording' => array(
      'label' => 'Recording',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'exclude' => 0,
      'id' => 'recording',
      'table' => 'dimdim',
      'field' => 'recording',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'start_date' => array(
      'order' => 'ASC',
      'granularity' => 'second',
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'start_date' => array(
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('empty', 'No upcoming web conferences.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'recording' => 'recording',
      'start_date' => 'start_date',
      'title' => 'title',
    ),
    'info' => array(
      'recording' => array(
        'separator' => '',
      ),
      'start_date' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Upcoming conferences', 'page_1');
  $handler->override_option('filters', array(
    'start_date' => array(
      'operator' => '>=',
      'value' => array(
        'type' => 'offset',
        'value' => '+0 day',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('path', 'dimdim/upcoming');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Upcoming Events',
    'description' => 'Upcoming Events',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('page', 'Previous Conferences', 'page_2');
  $handler->override_option('sorts', array(
    'start_date' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'start_date' => array(
      'operator' => '<=',
      'value' => array(
        'type' => 'offset',
        'value' => '+0 day',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('path', 'dimdim/past-events');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Past Events',
    'description' => 'Past Events',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $handler = $view->new_display('block', 'Next web conference (Block)', 'block_1');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'start_date' => array(
      'label' => 'Date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'start_date' => array(
      'operator' => '>=',
      'value' => array(
        'type' => 'offset',
        'value' => '+0 days',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'start_date',
      'table' => 'dimdim',
      'field' => 'start_date',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('items_per_page', 1);
  $handler->override_option('use_pager', '0');
  $handler->override_option('style_plugin', 'default');
  $handler->override_option('style_options', array());
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  
  $views[$view->name] = $view;
  return $views;
}
  
