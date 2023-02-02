import { createRouter, createWebHashHistory } from "vue-router";
import HomeView from "../views/HomeView";
import TableView from "../views/TableView";
import LoginView from "../views/LoginView";

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
  {
    path: "/login",
    name: "login",
    component: LoginView,
  },
];

const router = createRouter({
  history: createWebHashHistory(),
  routes,
});

export default router;
