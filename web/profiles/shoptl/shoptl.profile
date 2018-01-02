<?php
/**
 * @file
 * Enables modules and site configuration for a Shop TL site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function shoptl_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['#access'] = FALSE;
  $form['server_settings']['#access'] = FALSE;
  $form['update_notifications']['#access'] = FALSE;
}

/**
 * Implements hook_form_alter().
 *
 * Allow all field_* form fields title and description to be translated.
 */
function shoptl_form_alter(&$form, $form_state) {
  foreach (element_children($form) as $key) {
    if (strpos($key, 'field_') === 0) {
      $lang = $form[$key]['#language'];

      // Make root element title, description and options translatables.
      _shoptl_form_element_translate($form[$key][$lang]);

      // Make each delta title, description and options translatables.
      foreach (element_children($form[$key][$lang]) as $delta) {
        _shoptl_form_element_translate($form[$key][$lang][$delta]);

        // Make each delta's subelement title, description and options
        // translatables.
        foreach (element_children($form[$key][$lang][$delta]) as $subkey) {
          _shoptl_form_element_translate($form[$key][$lang][$delta][$subkey]);
        }
      }
    }
  }
}

/**
 * Helper to make a form element translatable.
 *
 * @param array $element
 *   The form element to make translatable.
 */
function _shoptl_form_element_translate(&$element) {
  if (!empty($element['#shoptl_translated'])) {
    return;
  }
  $element['#shoptl_translated'] = TRUE;

  if (!empty($element['#title'])) {
    $element['#title'] = t($element['#title']);
  }
  if (!empty($element['#description'])) {
    $element['#description'] = t($element['#description']);
  }
  if (!empty($element['#options'])) {
    foreach ($element['#options'] as $key => $value) {
      $element['#options'][$key] = t($value);
    }
  }
}

/**
 * Implements hook_field_attach_view_alter().
 *
 * Make fields labels and descriptions translatables.
 */
function shoptl_field_attach_view_alter(&$output, $context) {
  foreach (element_children($output) as $field_name) {
    $element = &$output[$field_name];
    if (!empty($element['#entity_type']) && !empty($element['#field_name']) && !empty($element['#bundle'])) {
      $instance = field_info_instance($element['#entity_type'], $element['#field_name'], $element['#bundle']);

      // Translate field title if set.
      if (!empty($instance['label'])) {
        $element['#title'] = t($element['#title']);
      }

      // Translate field description if set.
      if (!empty($instance['description'])) {
        $element['#description'] = t($element['#description']);
      }
    }
  }
}

/**
 * Implements hook_modules_enabled().
 *
 * Install translations for all modules.
 */
function shoptl_modules_enabled($modules) {
  // Install translations.
  $langs = language_list();
  foreach ($modules as $module) {
    $translations_dir = DRUPAL_ROOT . '/' . drupal_get_path('module', $module) . '/translations';
    foreach ($langs as $lang => $language) {
      $path = $translations_dir . '/' . $lang . '.po';
      if (!file_exists($path)) {
        $path = $translations_dir . '/' . $module . '.' . $lang . '.po';
      }
      if (!file_exists($path)) {
        $path = 'sites/all/translations/' . $module . '.' . $lang . '.po';
      }
      if (file_exists($path)) {
        $file = (object) array('filename' => basename($path), 'uri' => $path);
        _locale_import_po($file, $lang, LOCALE_IMPORT_OVERWRITE, 'default');
      }
    }
  }
}
