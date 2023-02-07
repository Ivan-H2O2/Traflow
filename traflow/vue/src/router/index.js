import { createRouter, createWebHashHistory } from "vue-router";
// import Router from "vue-router";
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
  mode: "history",
  history: createWebHashHistory(),
  routes,
});

export default router;

// export default new Router({
//   // mode: "history",
//   routes: [
//     {
//       path: "/home",
//       name: "home",
//       component: HomeView,
//     },
//     {
//       path: "/table",
//       name: "table",
//       component: TableView,
//     },
//     {
//       path: "/login",
//       name: "login",
//       component: LoginView,
//     },
//   ],
// });
