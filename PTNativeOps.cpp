#include <ATen/ATen.h>
#include <torch/torch.h>

#define CHECK_CUDA(x) AT_ASSERTM(x.type().is_cuda(), #x " must be a CUDA tensor")
#define CHECK_CONTIGUOUS(x) AT_ASSERTM(x.is_contiguous(), #x " must be contiguous")
#define CHECK_INPUT(x) CHECK_CUDA(x); CHECK_CONTIGUOUS(x)

void lstm_fwd_func_low_mem_var(
    at::Tensor X,
    at::Tensor W,
    at::Tensor b,
    at::Tensor y0,
    at::Tensor c0,
    at::Tensor i,
    int start,
    int step,
    at::Tensor Y,
    at::Tensor C,
    at::Tensor d,
    at::Tensor x_h,
    at::Tensor intern
);

void lstm_bwd_func_low_mem_var(
    at::Tensor X, at::Tensor W, at::Tensor b, at::Tensor y0, at::Tensor c0, at::Tensor i, int start, int step,
    at::Tensor Y, at::Tensor C,
    at::Tensor DY, at::Tensor Dd,
    at::Tensor DX, at::Tensor DW, at::Tensor Db, at::Tensor Dh, at::Tensor Dc,
    at::Tensor x_h, at::Tensor intern
);

void lstm_fwd_func_low_mem(
    at::Tensor X,
    at::Tensor W,
    at::Tensor b,
    at::Tensor y0,
    at::Tensor c0,
    at::Tensor i,
    int start,
    int step,
    at::Tensor Y,
    at::Tensor C,
    at::Tensor d
);

void lstm_bwd_func_low_mem(
    at::Tensor X, at::Tensor W, at::Tensor b, at::Tensor y0, at::Tensor c0, at::Tensor i, int start, int step,
    at::Tensor Y, at::Tensor C,
    at::Tensor DY, at::Tensor Dd,
    at::Tensor DX, at::Tensor DW, at::Tensor Db, at::Tensor Dh, at::Tensor Dc
);

void lstm_fwd_func(
    at::Tensor X, at::Tensor W, at::Tensor y0, at::Tensor c0, at::Tensor i,
    int start, int step,
    at::Tensor Y, at::Tensor C, at::Tensor H, at::Tensor d, at::Tensor y_prev
);

void lstm_bwd_func(
    at::Tensor X, at::Tensor W, at::Tensor y0, at::Tensor c0, at::Tensor i,
    int start, int step,
    at::Tensor Y, at::Tensor C, at::Tensor H,
    at::Tensor DY, at::Tensor Dd, at::Tensor DX, at::Tensor DW, at::Tensor Dy0, at::Tensor Dc0,
    at::Tensor dx0
);

void lstm_fwd_func_base(
    at::Tensor Z, at::Tensor Wr, at::Tensor c, at::Tensor i,
    at::Tensor Y, at::Tensor d
);

void lstm_bwd_func_base(
    at::Tensor Wr, at::Tensor c, at::Tensor i, at::Tensor Y,
    at::Tensor Dd, at::Tensor DZ, at::Tensor DWr, at::Tensor Dc, at::Tensor tmpDc
);

void lstm_fwd_op_low_mem_var(
    at::Tensor X,
    at::Tensor W,
    at::Tensor b,
    at::Tensor y0,
    at::Tensor c0,
    at::Tensor i,
    int start,
    int step,
    at::Tensor Y,
    at::Tensor C,
    at::Tensor d,
    at::Tensor x_h,
    at::Tensor intern
)
{
    CHECK_INPUT(X);   CHECK_INPUT(W);  CHECK_INPUT(b);
    CHECK_INPUT(y0);  CHECK_INPUT(c0); CHECK_INPUT(i);
    CHECK_INPUT(Y);   CHECK_INPUT(C);  CHECK_INPUT(d);
    CHECK_INPUT(x_h); CHECK_INPUT(intern);
    lstm_fwd_func_low_mem_var(X, W, b, y0, c0, i, start, step, Y, C, d, x_h, intern);
}

void lstm_bwd_op_low_mem_var(
    at::Tensor X, at::Tensor W, at::Tensor b, at::Tensor y0, at::Tensor c0, at::Tensor i, int start, int step,
    at::Tensor Y, at::Tensor C,
    at::Tensor DY, at::Tensor Dd,
    at::Tensor DX, at::Tensor DW, at::Tensor Db, at::Tensor Dh, at::Tensor Dc,
    at::Tensor x_h, at::Tensor intern
)
{
    CHECK_INPUT(X);   CHECK_INPUT(W);   CHECK_INPUT(b);   CHECK_INPUT(y0);  CHECK_INPUT(c0);  CHECK_INPUT(i);
    CHECK_INPUT(Y);   CHECK_INPUT(C);
    CHECK_INPUT(DY);  CHECK_INPUT(Dd);
    CHECK_INPUT(DX);  CHECK_INPUT(DW);  CHECK_INPUT(Db);  CHECK_INPUT(Dh);  CHECK_INPUT(Dc);
    CHECK_INPUT(x_h); CHECK_INPUT(intern);
    lstm_bwd_func_low_mem_var(X, W, b, y0, c0, i, start, step, Y, C, DY, Dd, DX, DW, Db, Dh, Dc, x_h, intern);
}

void lstm_fwd_op_low_mem(
    at::Tensor X,
    at::Tensor W,
    at::Tensor b,
    at::Tensor y0,
    at::Tensor c0,
    at::Tensor i,
    int start,
    int step,
    at::Tensor Y,
    at::Tensor C,
    at::Tensor d
)
{
    CHECK_INPUT(X);   CHECK_INPUT(W);  CHECK_INPUT(b);
    CHECK_INPUT(y0);  CHECK_INPUT(c0); CHECK_INPUT(i);
    CHECK_INPUT(Y);   CHECK_INPUT(C);  CHECK_INPUT(d);
    lstm_fwd_func_low_mem(X, W, b, y0, c0, i, start, step, Y, C, d);
}

void lstm_bwd_op_low_mem(
    at::Tensor X, at::Tensor W, at::Tensor b, at::Tensor y0, at::Tensor c0, at::Tensor i, int start, int step,
    at::Tensor Y, at::Tensor C,
    at::Tensor DY, at::Tensor Dd,
    at::Tensor DX, at::Tensor DW, at::Tensor Db, at::Tensor Dh, at::Tensor Dc
)
{
    CHECK_INPUT(X);   CHECK_INPUT(W);   CHECK_INPUT(b);   CHECK_INPUT(y0);  CHECK_INPUT(c0);  CHECK_INPUT(i);
    CHECK_INPUT(Y);   CHECK_INPUT(C);
    CHECK_INPUT(DY);  CHECK_INPUT(Dd);
    CHECK_INPUT(DX);  CHECK_INPUT(DW);  CHECK_INPUT(Db);  CHECK_INPUT(Dh);  CHECK_INPUT(Dc);
    lstm_bwd_func_low_mem(X, W, b, y0, c0, i, start, step, Y, C, DY, Dd, DX, DW, Db, Dh, Dc);
}

void lstm_fwd_op(
    at::Tensor X, at::Tensor W, at::Tensor y0, at::Tensor c0, at::Tensor i,
    int start, int step,
    at::Tensor Y, at::Tensor C, at::Tensor H, at::Tensor d, at::Tensor y_prev
)
{
    CHECK_INPUT(X);       CHECK_INPUT(W);     CHECK_INPUT(y0);
    CHECK_INPUT(c0);      CHECK_INPUT(i);
    CHECK_INPUT(Y);       CHECK_INPUT(C);     CHECK_INPUT(H);
    CHECK_INPUT(d);
    CHECK_INPUT(y_prev);
    lstm_fwd_func(X, W, y0, c0, i, start, step, Y, C, H, d, y_prev);
}

void lstm_bwd_op(
    at::Tensor X, at::Tensor W, at::Tensor y0, at::Tensor c0, at::Tensor i,
    int start, int step,
    at::Tensor Y, at::Tensor C, at::Tensor H,
    at::Tensor DY, at::Tensor Dd,
    at::Tensor DX, at::Tensor DW, at::Tensor Dy0, at::Tensor Dc0, at::Tensor dx0
)
{
    CHECK_INPUT(X);       CHECK_INPUT(W);     CHECK_INPUT(y0);
    CHECK_INPUT(c0);      CHECK_INPUT(i);
    CHECK_INPUT(Y);       CHECK_INPUT(C);     CHECK_INPUT(H);
    CHECK_INPUT(DY);      CHECK_INPUT(Dd);    CHECK_INPUT(DX);
    CHECK_INPUT(DW);      CHECK_INPUT(Dy0);   CHECK_INPUT(Dc0);
    CHECK_INPUT(dx0)
    lstm_bwd_func(X, W, y0, c0, i, start, step, Y, C, H, DY, Dd, DX, DW, Dy0, Dc0, dx0);
}

void lstm_fwd_op_base(
    at::Tensor Z, at::Tensor Wr, at::Tensor c, at::Tensor i,
    at::Tensor Y, at::Tensor d
){
    CHECK_INPUT(Z);       CHECK_INPUT(Wr);     CHECK_INPUT(c);
    CHECK_INPUT(i);       CHECK_INPUT(Y);       CHECK_INPUT(d);
    lstm_fwd_func_base(Z, Wr, c, i, Y, d);
}

void lstm_bwd_op_base(
    at::Tensor Wr, at::Tensor c, at::Tensor i, at::Tensor Y,
    at::Tensor Dd, at::Tensor DZ, at::Tensor DWr, at::Tensor Dc, at::Tensor tmpDc
){
    CHECK_INPUT(Wr);       CHECK_INPUT(c);     CHECK_INPUT(i);
    CHECK_INPUT(Y);       CHECK_INPUT(Dd);       CHECK_INPUT(DZ);
    CHECK_INPUT(DWr);       CHECK_INPUT(Dc);     CHECK_INPUT(tmpDc);
    lstm_bwd_func_base(Wr, c, i, Y, Dd, DZ, DWr, Dc, tmpDc);
}

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("lstm_forward_op_low_mem", &lstm_fwd_op_low_mem, "LSTM forward low mem");
  m.def("lstm_backward_op_low_mem", &lstm_bwd_op_low_mem, "LSTM backward low mem");
  m.def("lstm_forward_op_low_mem_var", &lstm_fwd_op_low_mem_var, "LSTM forward low mem var");
  m.def("lstm_backward_op_low_mem_var", &lstm_bwd_op_low_mem_var, "LSTM backward low mem var");
  m.def("lstm_forward_op", &lstm_fwd_op, "LSTM forward");
  m.def("lstm_backward_op", &lstm_bwd_op, "LSTM backward");
  m.def("lstm_forward_op_base", &lstm_fwd_op_base, "LSTM forward Base");
  m.def("lstm_backward_op_base", &lstm_bwd_op_base, "LSTM backward Base");
}