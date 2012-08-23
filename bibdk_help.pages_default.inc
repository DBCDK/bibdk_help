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

$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'user_help';
$page->task = 'page';
$page->admin_title = 'User help';
$page->admin_description = 'This page is for showing the user help nodes in a pop-up window.';
$page->path = 'help/!bibdk_help_context';
$page->access = array();
$page->menu = array();
$page->arguments = array(
  'bibdk_help_context' => array(
    'id' => 1,
    'identifier' => 'bibdk help: Node ID',
    'name' => 'bibdk_help_arg',
    'settings' => array(),
  ),
);
$page->conf = array(
  'admin_paths' => FALSE,
);
$page->default_handlers = array();
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
    'override_title' => 1,
    'form_build_id' => 'form-FzNdE-JDMwGKLL-iDvcECcDNKvJgOcpp6hkf7vNbnG0',
    'form_token' => 'egVpx0Jvpd2MHJKccCz0VrgSw_kPhGrr4qm6xHhdCuE',
    'form_id' => 'bibdk_help_edit_form',
    'override_title_text' => '',
    'helptext_id' => '0',
    'buttons' => NULL,
    'aligner_start' => NULL,
    'aligner_stop' => NULL,
    'override_title_markup' => NULL,
    'context' => 'argument_bibdk_help_arg_1',
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
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;

  $pages['user_help'] = $page;

  return $pages;
}