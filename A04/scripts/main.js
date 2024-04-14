/* 
Programmer: Michele Roosje
Date: April 12, 2024
Program: main.js
*/

"use stirct";
document.addEventListener("DOMContentLoaded", init);

function init() {
  console.log("I'm in the init function!")

  require(["esri/config",
    "esri/Map",
    "esri/views/MapView",

    //add widgets
    "esri/widgets/Home",
    "esri/widgets/ScaleBar",
    "esri/widgets/Measurement",
    "esri/widgets/Legend",

    //add layers
    "esri/layers/FeatureLayer",
    "esri/layers/GeoJSONLayer",

    "esri/Graphic",
    "esri/layers/GraphicsLayer",

    //add symbology modules
    "esri/symbols/SimpleFillSymbol",
    "esri/renderers/SimpleRenderer",
    "esri/symbols/SimpleMarkerSymbol",
    "esri/PopupTemplate"
  ],

    function (esriConfig, Map, MapView, Home, ScaleBar, Measurement, Legend, FeatureLayer, GeoJSONLayer, Graphic, GraphicsLayer,
      SimpleFillSymbol, SimpleRenderer, SimpleMarkerSymbol, PopupTemplate) {

      //api key from developer account to access ESri's basemaps
      esriConfig.apiKey = "AAPK598a992207a54013b85e5db902ae5acafea0L6PMgGsfGCLAFPDDqMmNRR8sonE862a6_hDyZKSBs3vMYja-TT6kqCIt-lkg";

      // create a map
      const map = new Map({
        basemap: "osm/navigation" // basemap styles service
      });

      //create a view
      //add graphics layer to map
      const view = new MapView({
        map: map,
        center: [-65.2884, 44.8418], //Longitude, latitude
        zoom: 15,
        container: "viewDiv"
      });

      //
      //add home widget
      //
      let homeWidget = new Home({
        view: view
      });

      // adds the home widget to the top left corner of the MapView
      view.ui.add(homeWidget, "top-left");

      //
      //add scale bar widget
      //
      let scaleBar = new ScaleBar({
        view: view,
        unit: "metric",
        style: "line"
      });

      // Add widget to the top-right corner of the view
      view.ui.add(scaleBar, {
        position: "bottom-right"
      });

       // add legand widget
       let legend = new Legend({
        view: view
      });
      
      view.ui.add(legend, "bottom-left");

      // let measurement = new Measurement({
      //   view: view,
      //   activeTool: "distance"
      // });
      // view.ui.add(measurement, "top-right");


      
      
        const foodRender = new SimpleRenderer({
          symbol: new SimpleMarkerSymbol({
            style: "images/food.svg"
            

          })
        });

      //add GeoJSON layer to the map
      const foodGeoJSONLayer = new GeoJSONLayer({
        url: "geojsons/food.geojson",
        renderer: foodRender

      });

      map.add(foodGeoJSONLayer);  // adds the layer to the map



      const funRender = new SimpleRenderer({
        symbol: new SimpleFillSymbol({
          style: "solid",
          color: "green"

        })
      });

      const funPopup = {
        title: "Bridgetown Family Fun",
        content: [{
          type: "fields",
          fieldInfos: [{
            fieldName: "name",
            label: "Fun Area"
          }, {
            fieldName:"cost",
            Lable: "Cost"
          }]
        }]
      }

      const funGeoJSONLayer = new GeoJSONLayer({
        url: "geojsons/fun.geojson",
        renderer: funRender,
        popupTemplate: funPopup

      });

     


      map.add(funGeoJSONLayer);  // adds the layer to the map

    

  

    }); //end of the require function Everything should go before this

}