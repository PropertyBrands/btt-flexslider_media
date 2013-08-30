<?php
$output = "";
$slides = "";
$controls = "";
$link = "";
$flexcontrols = $element['#settings']['controls']['use_flex'];

if(isset($element['controls'])) {
  foreach($element['controls'] as $fid => $control) {
    $controls .= '<li class="control">' . (!$flexcontrols ? '<a href="#" onclick="jQuery(\'.' . $container_class . ' .slider\').flexslider(' . $fid . '); return false;">' : '') . drupal_render($control) . (!$flexcontrols ? '</a>' : '') . '</li>';
  }
  $controls = '<div class="controls ' . ($flexcontrols ? 'flexslider' : ''). '"><ul class="slides">' . $controls . '</ul></div>';
 
}


if(isset($element['slides'])) {
  foreach($element['slides'] as $fid => $slide) {
    $slides .= '<li class="slide">' . drupal_render($slide) . '</li>';
  }
 
  $slides = '<div class="slider flexslider"><ul class="slides">' . $slides . '</ul></div>';
}
//if(isset($element['#settings']['limit_link']) && $element['#settings']['limit_link'] && isset($element['#settings']['limit']) && $element['#settings']['limit'] > 0 && isset($element['#settings']['items_total']) && $element['#settings']['items_total'] > $element['#settings']['limit']) {
//  $more_ct = $element['#settings']['items_total'] - $element['#settings']['limit'];
//  $uri = entity_uri($element['#entity_type'], $element['#object']);
//  $link = l(format_plural($more_ct, '@ct more photo', '@ct more photos', array('@ct' => $more_ct)), $uri['path'], $uri['options']);
//  $link = "<div class=\"rcd-flexslider-link\">$link</div>";
//}
$output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $slides . $controls . $link . '</div>';

print($output);