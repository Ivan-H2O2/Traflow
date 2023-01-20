import { createRouter, createWebHashHistory } from "vue-router";
import HomeView from "../views/HomeView";

const routes = [
  {
    path: "/",
    name: "home",
    component: HomeView,
  },
];

const router = createRouter({
  history: createWebHashHistory(),
  routes,
});

export default router;
