<?php

/**
 * @file
 * Bibdk user helptext: ctools content type.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Bibliotek.dk user help'),
  'content_types' => 'bibdk_help',
  'single' => TRUE,
  'render callback' => 'bibdk_help_render',
  'description' => t('Bibliotek.dk user help content type.'),
  'required context' => new ctools_context_required(t('bibdk_help_context'), 'bibdk_help_context'),
  'edit form' => 'bibdk_help_edit_form',
  'category' => array(t('Ding!'), -9),
);


/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *
 * @return
 *   An object with at least title and content members
 */
function bibdk_help_render($subtype, $conf, $args, $context) {

// bibdk_help_update_index();

  $data = $context->data;
  $block = new stdClass();
  $nid = FALSE;

  if (!empty($conf) && isset($conf['helptext_id'])) {
    $nid = (int)$conf['helptext_id'];
  }
  if (!empty($args) && !$nid) {
    $nid = (int)$args[0];
  }
  if (!empty($data->nid) && !$nid) {
    $nid = (int)$data->nid;
  }

  // The title actually used in rendering.
  $block->title = "Bibliotek.dk user help content type";

  // Build Breadcrumbs
  $breadcrumb[] = l('Help', 'help');

  if ( $nid ) {
    $node = node_load($nid);
    if ( !$node ) {
      drupal_set_message(t('The help node does not exist.'), 'warning');
      return $block;
    }
    $breadcrumb[] = l($node->title, current_path());
    drupal_set_breadcrumb($breadcrumb);
    $nodeview = node_view($node, 'full');
    $nodeview['help_url'] = '/help/' . $nid;
    $nodeview['#contextual_links']['node'][0] = 'help';
    $block->content = $nodeview;
    return $block;
  }

  $renderable_array = array();
  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.status = :status';
  $result = db_query($sql,
    array(
      ':type' => 'userhelp',
      ':status' => 1,
    )
  );

  $renderable_array['explanation'] = array(
    '#markup' => '<p>' . t("This list is a list of help texts.") . '</p>',
  );

  foreach ($result as $row) {
    $node = node_load($row->nid);
    $nodeview = node_view($node, 'bibdk_help_list');
    $nodeview['help_url'] = '/help/' . $row->nid;
    $nodeview['#contextual_links']['node'][0] = 'help';
    $renderable_array['node_list'][]= $nodeview;
  }

  $block->content = $renderable_array;

  return $block;

}


/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function bibdk_help_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['helptext_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID:'),
    '#size' => 5,
    '#description' => t('Optional: Help text node ID.'),
    '#default_value' => !empty($conf['helptext_id']) ? $conf['helptext_id'] : '0',
  );
  return $form;
}


function bibdk_help_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
