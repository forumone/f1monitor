<?php

$plugin = array(
  'callback' => 'f1monitor_caching_is_on',
);

/**
 * Check whether caching is turned on and return a structure as expected of hook_requirements().
 */
function f1monitor_caching_is_on() {
  $cache = variable_get('cache', false);

  $pos_desciption = t('Caching for anonymous users is enabled.');
  $neg_description = t('Caching for anonymous users is disabled, for better performance, visit the <a href="/admin/config/development/performance">perfomance settings</a> and enable it.');

  $requirement = array(
    'title' => t('Cache pages for Anonymous users.'),
    'value' => $cache ? t('Enabled') : t('Disabled'),
    'description' => $cache ? $pos_desciption : $neg_description,
    'severity' => $cache ? REQUIREMENT_OK : REQUIREMENT_WARNING,
  );

  return array(
    'f1monitor_caching' => $requirement,
  );
}
