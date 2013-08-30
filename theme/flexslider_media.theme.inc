<?php
/**
 * 
 *
 * @param array $vars
 */
function flexslider_media_preprocess_flexslider_media_formatter(&$vars) {
  //drupal_add_js(libraries_get_path('flexslider') . "/jquery.flexslider.js");
  //drupal_add_css(libraries_get_path('flexslider') . "/flexslider.css");
  flexslider_media_add_includes();



  $js['containerClass'] = $vars['container_class'] = 'flexslider-media-' . $vars['element']['#entity_type'] . "-" . implode(entity_extract_ids($vars['element']['#entity_type'], $vars['element']['#object']), '-');
  $vars['classes_array'][] = 'flexslider-media';
  $vars['classes_array'][] = $vars['container_class'];
  $element = $vars['element'];
  $view_mode_full  = $element['#settings']['view_mode_full'];
  $view_mode_thumb = $element['#settings']['controls']['view_mode_thumb'];


  $js['itemWidth'] = isset($element['#settings']['controls']['flex_width']) ? $element['#settings']['controls']['flex_width'] : 120;
$js['useFlexControls'] = !(empty($element['#settings']['controls']['use_flex']));
  $js['sync'] = (!empty($element['#settings']['controls']['use_flex'])) ? $js['fsmContainerClass'] . " .controls" : "";

  foreach($element['#items'] as $index => $item) {
    $full = '';
    $fid = $item['fid'];
    $file = entity_load('file', array($fid));



    $vars['element']['slides'][$fid] =  file_view($file[$fid], $view_mode_full);

    if($element['#settings']['controls']['use_flex'] == 1) {
      $vars['element']['controls'][$fid] = file_view($file[$fid], $view_mode_thumb);

    }

    

  }

  $settings = array(
    'flexslider_media' => $js
  );

  drupal_add_js(array('flexslider_media' => $js), 'setting');
}
