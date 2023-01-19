import { createApp } from "vue";
import App from "./App.vue";
import router from "./router";
import store from "./store";

import ElementPlus from "element-plus";
import "element-plus/dist/index.css";
// 引入global的css文件
import "@/assets/css/global.css";
// 引入element-ui 的 icon
import * as ElementPlusIconsVue from "@element-plus/icons-vue";
const app = createApp(App);
for (const [key, component] of Object.entries(ElementPlusIconsVue)) {
  app.component(key, component);
}
createApp(App).use(store).use(ElementPlus).use(router).mount("#app");
