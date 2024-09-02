const fs = require("fs");
const path = require("path");
const syntaxHighlight = require("@11ty/eleventy-plugin-syntaxhighlight");
const execSync = require("child_process").execSync;

module.exports = function (eleventyConfig) {
  // Add syntax highlighting
  eleventyConfig.addPlugin(syntaxHighlight);
  eleventyConfig.addCollection("pages", function (collectionApi) {
    return collectionApi.getAll();
  });
  // Run Sass compilation
  eleventyConfig.on("beforeBuild", () => {
    execSync("node scripts/sass-compile.cjs", { stdio: "inherit" });
  });
  // Copy the compiled CSS files
  eleventyConfig.addPassthroughCopy("assets/css/styles.css");
  // Copy images

  eleventyConfig.addPassthroughCopy(
    "hardware-prototypes/Boxnet/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hardware-prototypes/Boxnet/images/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/alfredo-nina/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/alfredo-nina/images/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/decision-maker_sujing/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/decision-maker_sujing/images/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/dropzer_v1_daniel/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/dropzer_v1_daniel/images/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/machine_talking/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "hid-prototypes/machine_talking/images/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "video-prototypes/brainlink-daniel-paul/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "video-prototypes/brainlink-daniel-paul/images/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "video-prototypes/mikronerv-sujing-nina/**/*.{png,*jpg,*jpeg,*gif}",
  );
  eleventyConfig.addPassthroughCopy(
    "video-prototypes/mikronerv-sujing-nina/images/**/*.{png,*jpg,*jpeg,*gif}",
  );

  // Copy assets folder
  eleventyConfig.addPassthroughCopy("assets");

  // Pass through assets
  eleventyConfig.addPassthroughCopy("assets");
  eleventyConfig.addShortcode("include_relative", function (file) {
    const fullPath = path.join(this.page.inputPath, "..", file);
    return fs.readFileSync(fullPath, "utf8");
  });
  // Set input and output directories
  return {
    dir: {
      input: ".",
      output: "_site",
      includes: "_includes",
      layouts: "_layouts",
    },
    templateFormats: ["html", "md", "liquid"],
    passthroughFileCopy: true,
  };
};
