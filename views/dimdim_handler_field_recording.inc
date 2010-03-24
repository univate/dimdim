<?php

class dimdim_handler_field_recording extends views_handler_field {
  /**
   * Render the field.
   *
   * @param $values
   *   The values retrieved from the database.
   */
  function render($values) {
    drupal_add_js(drupal_get_path('module', 'dimdim') .'/dimdim.js', 'module');
    modalframe_parent_js();
    $value = $values->{$this->field_alias};
    if (!empty($value)) {
      return l('play', 'node/'. $values->nid .'/dimdim/recording', array('attributes' => array('class' => 'dimdim-recording-link')));
    }
    else {
      return 'no recording';
    }
  }
}
