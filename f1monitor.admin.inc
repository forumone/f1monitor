<?php

/**
 * Page callback for /admin/reports/f1monitor
 */
function f1monitor_report() {

  $page_content = '';
  $data = array();

  $plugins = f1monitor_get_content_types();
  $report = f1monitor_gather_plugin_data($plugins);

  $score = 0;
  foreach($report as $id => $item) {
    if($item['severity'] == REQUIREMENT_WARNING || $item['severity'] == REQUIREMENT_ERROR) {
      $score++;
    }
  }

  $summary = f1monitor_get_report_summary($score);

  return  $summary . theme('status_report', array('requirements' => $report));
}

/**
 * Generate a textual summary of the report.
 */
function f1monitor_get_report_summary($score) {
  //TODO Pluralize when appropriate.

  $text = 'F1 Monitoring found %d opportunity for improvement.';

  if($score > 1) {
    $text = 'F1 Monitoring found %d opportunities for improvement.';
  }

  return t($text, array('%d' => $score));
}