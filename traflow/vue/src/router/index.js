import { createRouter, createWebHashHistory } from "vue-router";
import HomeView from "../views/HomeView";
import TableView from "../views/TableView";

const routes = [
  {
    path: "/home",
    name: "home",
    component: HomeView,
  },
  {
    path: "/table",
    name: "table",
    component: TableView,
  },
];

const router = createRouter({
  history: createWebHashHistory(),
  routes,
});

export default router;
