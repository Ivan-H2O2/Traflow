import { createApp } from "vue";
import App from "./App.vue";
import router from "./router";
import store from "./store";

import ElementPlus from "element-plus";
import "element-plus/dist/index.css";

import "@/assets/css/global.css";

createApp(App).use(store).use(ElementPlus).use(router).mount("#app");
