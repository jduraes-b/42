const cart = [];
document.querySelectorAll('.add-to-cart').forEach(button => {
  button.addEventListener('click', () => {
    const productId = button.dataset.productId;
    cart.push(productId);
    document.getElementById('cart-count').textContent = cart.length;
    // Optional: show a toast or modal
  });
});
