<?php

/**
 * Return a help text search form.
 */
function bibdk_help_search_form($form, &$form_state) {

  $form['userhelp'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Search help texts.'),
    '#tree'         => TRUE,
  );

  $form['userhelp']['search_help'] = array(
    '#type' => 'textfield',
    '#title' => t('Search help:'),
    '#title_display'  => 'invisible',
    '#size' => 5,
    '#default_value' => !empty($form_state['values']['userhelp']['search_help']) ? $form_state['values']['userhelp']['search_help'] : '',
  );

  $form['#submit'][] = 'bibdk_help_search_form_submit';
  $form['#validate'][] = 'bibdk_help_search_form__validate';

  $form['userhelp']['actions'] = array('#type' => 'actions');
  $form['userhelp']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  return $form;
}

/**
 * Submit handler for bibdk_help_search_form();
 */
function bibdk_help_search_form_submit($form, &$form_state) {
  dpm($form_state['values']);
}

/**
 * Validation handler for bibdk_help_search_form();
 */
function bibdk_help_search_form__validate($form, &$form_state) {
  if ( !$form_state['values']['userhelp']['search_help'] ) {
    form_set_error('search_help', t('Enter a search term.', array()));
  }
}
