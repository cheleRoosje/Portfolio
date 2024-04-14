/*
FileName: main.js
Programmer: Michele Roosje
Date: March 16, 2024
Note: npm start in terminal to serve
*/

import './style.css';
import {Map, View} from 'ol';
import TileLayer from 'ol/layer/Tile';
import OSM from 'ol/source/OSM';
import {fromLonLat} from 'ol/proj';

// add mouse control modules
import MousePosition from 'ol/control/MousePosition.js';
import {createStringXY} from 'ol/coordinate';
import { loadFeaturesXhr } from 'ol/featureloader';

// add GeoJSON modules
import VectorLayer from 'ol/layer/Vector';
import GeoJSON from 'ol/format/GeoJSON';
import {Vector as VectorSource} from 'ol/source';

// add style modules
import {Style, Stroke, Fill} from 'ol/Style';

//add event listener to run init function after Dom loads
document.addEventListener("DOMContentLoaded", init);
function init() {

  // Add event listener to checkbox change
  document.querySelectorAll('input[type=checkbox]').forEach(function(checkbox) {
    checkbox.addEventListener('change', function() {
      const layerName = this.name;
      const checked = this.checked;
      console.log("Checkbox change:", layerName, checked); // Check if event listener is triggered
      toggleLayerVisibility(layerName, checked);
    });
  });

  // Update basemap selection based on radio button change
document.querySelectorAll('input[type=radio][name=basemap]').forEach(function(radio) {
  radio.addEventListener('change', function() {
      if (this.value === 'basemap1') {
          myMap.getLayers().setAt(0, basemap1);
      } else if (this.value === 'basemap2') {
          myMap.getLayers().setAt(0, basemap2);
      }
  });
});

  //basemap1 default
  let basemap1 = new TileLayer({
    source: new OSM()
  })

  //basemap2 
let basemap2 = new TileLayer({
  source: new OSM({"url": "https://server.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/{z}/{y}/{x}"})
})

//initialize map with basemap1 as default
const myMap = new Map({
  target: 'mainMap',
  layers: [
   basemap1
  ],
  view: new View({
    center: fromLonLat([-65.50599023, 44.74164283]),
    zoom: 15
  })
});

//define mouse control parameters
const mousePositionControl = new MousePosition({
  coordinateFormat: createStringXY(2),
  projection: 'EPSG:4326',
  target: document.getElementById('mouse-position'),
});

//Modify createStringXY function to include labels
function createStringXY(decimalPlaces){
  return function(coordinate){
    const x = coordinate[0].toFixed(decimalPlaces);
    const y = coordinate[1].toFixed(decimalPlaces);

    return 'Longitude: ' +x+ ', Latitude: ' +y;
  };
}

//add mouse control to map
myMap.addControl(mousePositionControl);

// call addWindsorLayers function to add GeoJSON symbolized files
addWindsorLayers(myMap);
}

function addWindsorLayers(myMap){

  //define walking trails style
  let walkStyle = new Style({
    stroke: new Stroke({
      color: 'green',
      width: 5,
      lineDash: [10, 10]
    })
  })

//define walking trails GeoJSON layer
let walkFile = './geojson/walk.geojson'
let walkLyr = new VectorLayer({
  source: new VectorSource({
    url: walkFile,
    format: new GeoJSON()
  }),
  style: walkStyle,
  name: 'walk'
});

//define sites style
let siteStyle = new Style({
  stroke: new Stroke({
    color: 'orange',
    width: 2,
  }),
  fill: new Fill({
    color: 'rgba(255, 255, 0, .3)'
  })
})

//define sites GeoJSON layer
let siteFile = './geojson/sites.geojson'
let siteLyr = new VectorLayer({
  source: new VectorSource({
    url: siteFile,
    format: new GeoJSON()
  }),
  style: siteStyle,
  name: 'sites'
});

//add layers to map
myMap.addLayer(walkLyr);
myMap.addLayer(siteLyr);
}