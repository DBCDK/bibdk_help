<?php

/**
 * @file
 * ding_library.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function bibdk_help_default_page_manager_pages() {
  $pages = array();

$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_user_help_panel_context';
$handler->task = 'page';
$handler->subtask = 'user_help';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
);
$display = new panels_display();
$display->layout = 'onecol';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'middle' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bibdk_help-bibdk-help-form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $display->content['new-1'] = $pane;
  $display->panels['middle'][0] = 'new-1';
  $pane = new stdClass();
  $pane->pid = 'new-2';
  $pane->panel = 'middle';
  $pane->type = 'bibdk_help';
  $pane->subtype = 'bibdk_help';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'context' => 'argument_bibdk_help_arg_1',
    'aligner_start' => NULL,
    'override_title' => 1,
    'override_title_text' => '',
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'helptext_id' => '0',
    'form_build_id' => 'form-OxfBLRF7pSAslIDvylGICFx0PxnP9e09rJglYcVBpUg',
    'form_token' => 'zxh4eqWmoGNPdqvT40sYHyP0r0wY-ePZA6BhigcyyjY',
    'form_id' => 'bibdk_help_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $display->content['new-2'] = $pane;
  $display->panels['middle'][1] = 'new-2';
  $pane = new stdClass();
  $pane->pid = 'new-3';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'menu-user-help-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'bibdk-user-help-menu',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $display->content['new-3'] = $pane;
  $display->panels['middle'][2] = 'new-3';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;

  $page->default_handlers[$handler->name] = $handler;

  $pages['node_view'] = $page;

  return $pages;
}