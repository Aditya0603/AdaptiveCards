"use strict";

// Copy various adaptive card assets from elsehwere in the repo into the output folder

var fs = require("hexo-fs");
var path = require("path");
var glob = require("glob");

var assets = [
    {
        // Sample payloads
        path: "../../../samples/v1.*/**/*.json",
        dest: function (p) { return "payloads/" + path.basename(p); }
    },
    {
        // JSON-schema file
        path: "../../../schemas/adaptive-card.json",
        dest: function (p) { return "schemas/adaptive-card.json"; }
    },
    {
        // renderer script
        path: "node_modules/adaptivecards/dist/adaptivecards.min.js",
        dest: function (p) { return "js/adaptivecards.min.js"; }
    },
    {
        // visualizer css
        path: "node_modules/adaptivecards-visualizer/css/*.css",
        dest: function (p) { return "visualizer/css/" + path.basename(p); }
    },
    {
        // visualizer css
        path: "node_modules/adaptivecards-visualizer/dist/*",
        dest: function (p) { return "visualizer/" + path.basename(p); }
    },
    {
        // visualizer assets
        path: "node_modules/adaptivecards-visualizer/assets/*",
        dest: function (p) { return "visualizer/assets/" + path.basename(p); }
    },
	{
        // monaco loader
        // this is a temp hack until Monaco works with webpack
        // https://github.com/Microsoft/monaco-editor/issues/18
        path: "../adaptivecards-designer/editor/monaco-loader.js",
        dest: function (p) { return "designer/monaco-loader.js" }
	},
	{
        // designer script
        path: "node_modules/adaptivecards-designer/dist/adaptivecards-designer.min.js",
        dest: function (p) { return "designer/adaptivecards-designer.min.js"; }
    },
    {
        // designer css
        path: "node_modules/adaptivecards-designer/css/*.css",
        dest: function (p) { return "designer/css/" + path.basename(p); }
    },
    {
        // designer assets
        path: "node_modules/adaptivecards-designer/assets/*",
        dest: function (p) { return "designer/assets/" + path.basename(p); }
    },
];

hexo.extend.generator.register("generator-adaptiveassets", function (locals) {

    var allAssets = [];

    assets.forEach(function (asset) {
        var g = glob.sync(asset.path, { nocase: false }).map(function (p) {

            return {
                path: asset.dest(p),
                data: function () {
                    return fs.createReadStream(p);
                }
            }
        });

        g.forEach(function (item) {

            allAssets.push(item);
        });
    });

    return allAssets;
});
