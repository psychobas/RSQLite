#include <Rcpp.h>
#include "SqliteResult.h"
using namespace Rcpp;

// [[Rcpp::export]]
XPtr<SqliteResult> rsqlite_send_query(XPtr<SqliteConnectionPtr> con, const std::string& sql) {
  SqliteResult* res = new SqliteResult((*con), sql);
  return XPtr<SqliteResult>(res, true);
}

// [[Rcpp::export]]
void rsqlite_clear_result(XPtr<SqliteResult>& res) {
  res.release();
}

// [[Rcpp::export]]
List rsqlite_fetch(const XPtr<SqliteResult>& res, int n = 10) {
  return res->fetch(n);
}

// [[Rcpp::export]]
void rsqlite_bind_params(const XPtr<SqliteResult>& res, List params) {
  res->bind(params);
}

// [[Rcpp::export]]
void rsqlite_bind_rows(const XPtr<SqliteResult>& res, List params) {
  res->bind_rows(params);
}


// [[Rcpp::export]]
bool rsqlite_has_completed(const XPtr<SqliteResult>& res) {
  return res->complete();
}

// [[Rcpp::export]]
int rsqlite_row_count(const XPtr<SqliteResult>& res) {
  return res->nrows() - 1;
}

// [[Rcpp::export]]
int rsqlite_rows_affected(const XPtr<SqliteResult>& res) {
  return res->rows_affected();
}

// [[Rcpp::export]]
List rsqlite_column_info(const XPtr<SqliteResult>& res) {
  return res->column_info();
}

// [[Rcpp::export]]
bool rsqlite_result_valid(const XPtr<SqliteResult>& res) {
  return res.get() != NULL;
}
