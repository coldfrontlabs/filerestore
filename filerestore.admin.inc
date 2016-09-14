<?php
/**
 * Admin forms for filerestore
 */

/**
 * Admin form for filerestore
 */
function filerestore_admin_form($form, &$form_state) {
  $form['migrate_unmanaged_files'] = array(
    '#type' => 'button',
    '#name' => 'migrate_unmanaged_files',
    '#value' => t('Migrate unmanaged files'),
    '#description' => t('Scan Drupal\'s public files directory for files which are not tracked by Drupal and import them as proper file entities.'),
    '#executes_submit_callback' => TRUE,
  );

  $form['#submit'][] = 'filerestore_admin_form_submit';

  return $form;
}

/**
 * Submit handler for filerestore_admin_form
 *
 * Trigger the batch process for importing new managed files
 */
function filerestore_admin_form_submit(&$form, &$form_state) {
  if ($form_state['triggering_element']['#name'] == 'migrate_unmanaged_files') {
    $batch = filerestore_batch_manage_files();
    batch_set($batch);
  }
}