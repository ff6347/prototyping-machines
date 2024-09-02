const sass = require("sass");
const fs = require("fs");
const path = require("path");

const inputDir = "assets/_scss";
const outputDir = "assets/css";

// Ensure the output directory exists
if (!fs.existsSync(outputDir)) {
  fs.mkdirSync(outputDir, { recursive: true });
}

// Compile all .scss files in the input directory
// fs.readdirSync(inputDir).forEach((file) => {
// Compile main .scss file
const inputFile = path.join(inputDir, "styles.scss");
const outputFile = path.join(outputDir, "styles.css");

const result = sass.compile(inputFile, {
  style: "compressed",
  loadPaths: [inputDir],
});

fs.writeFileSync(outputFile, result.css);
console.log(`Compiled ${inputFile} to ${outputFile}`);
// }
// });
